#include "Scene.hh"
#include "PowierzchniaMarsa.hh"
#include "lacze_do_gnuplota.hh"


void Scene::InitGnuplotLink(){
    Lacze.ZmienTrybRys(PzG::TR_3D);
    Lacze.UstawZakresX(-ROMIAR_POWIERZCHNI_X/2, ROMIAR_POWIERZCHNI_X/2);
    Lacze.UstawZakresY(-ROMIAR_POWIERZCHNI_Y/2, ROMIAR_POWIERZCHNI_Y/2);
    Lacze.UstawZakresZ(-0, 90);  
    Lacze.UstawRotacjeXZ(40,60); // Tutaj ustawiany jest widok
    Lacze.Inicjalizuj();  // Tutaj startuje gnuplot.
    if (!Inicjalizuj_PowierzchnieMarsa(Lacze)) 
        throw std::runtime_error("Error: Scene::InitGnuplotLink() Lacze nie zostalo zainicjowane poprawnie");
}



void Scene::AddRoverSFR(const char* sNameOfFile_ModelBlock, const char* sObjectName, int ColourID, 
    Vector3D Scale,Vector3D Position,
    double Angle, double Velocity, double Distance){
    RoverSFR z(sNameOfFile_ModelBlock,sObjectName,ColourID,Scale,Position,Angle,Velocity,Distance);
    std::shared_ptr<RoverSFR> x = std::make_shared<RoverSFR>(z);
    Objects.push_back(x);
    AddToDrawingList(*x);
    x->Count_and_save_tops();

}

void Scene::addRover(const char* sNameOfFile_ModelBlock, const char* sObjectName, int ColourID, 
                     Vector3D Scale, Vector3D Position,
                     double Angle, double Velocity, double Distance){
    Rover z(sNameOfFile_ModelBlock,sObjectName,ColourID,Scale,Position,Angle,Velocity,Distance);
    std::shared_ptr<Rover> x = std::make_shared<Rover>(z);
    Objects.push_back(x);
    AddToDrawingList(*x);
    x->Count_and_save_tops();
}

void Scene::addSample(const char* sObjectName, 
    Vector3D Scale,Vector3D Position){
    RegSample z(sObjectName,Scale,Position);
    std::shared_ptr<RegSample> x = std::make_shared<RegSample>(z);
    Objects.push_back(x);
    AddToDrawingList(*x);
    x->Count_and_save_tops();
}

void Scene::AddToDrawingList(Object &rOb){
    PzG::InfoPlikuDoRysowania *wInfoPliku;  
    wInfoPliku = &Lacze.DodajNazwePliku(rOb.ReturnNameOfFile_DrawBlock());
    wInfoPliku->ZmienKolor(rOb.ReturnColourID());
}

void Scene::DisplayRoversList()const{
    int size = Objects.size();
    Vector3D Pos;
    int x=0;
    if(size==0){
        std::cout<<"Empty list"<<std::endl;
        return;
    }
    for(std::shared_ptr<Object> Ob:Objects){
        if(Ob->ReturnType()==RoverT||Ob->ReturnType()==RoverSFRT){
        Pos = std::static_pointer_cast<Rover>(Ob)->returnPosition();
        ++x;
        std::cout<<x<<".       Nazwa:"<<Ob->ReturnObjectName()<<std::endl<<"       Pozycja:"<<Pos[0]<<" "<<Pos[1]<<" "<<Pos[2];
        std::cout<<std::endl<<"Orientacja(st):"<<std::static_pointer_cast<Rover>(Ob)->returnAngle()<<std::endl<<std::endl;
        }
    }
}

void Scene::DisplaySampleList()const{
    int size = Objects.size();
    Vector3D Pos;
    int x=0;
    if(size==0){
        std::cout<<"Empty list"<<std::endl;
        return;
    }
    std::cout<<"Lista niezebranych probek"<<std::endl;
    for(std::shared_ptr<Object> Ob:Objects){
        if(Ob->ReturnType()==Sample){
        ++x;
        Pos = std::static_pointer_cast<RegSample>(Ob)->ReturnPosition();
        std::cout<<x<<". "<<Ob->ReturnObjectName()<<"   Polozenie: "<<Pos[0]<<" "<<Pos[1]<<" "<<Pos[2]<<std::endl;
        }
    }
}

bool Scene::SelectRover(int choice){
    int size = Objects.size();
    int x = 0;
    if (choice>size) {
        return false;
    }
    for(std::shared_ptr<Object> Ob:Objects){
        if(Ob->ReturnType()!=RoverT&&Ob->ReturnType()!=RoverSFRT)
            continue;
        ++x;
        if(x==choice)
            ActiveRover = std::static_pointer_cast<Rover>(Ob);
        }
    return true;
}

void Scene::MoveRover(double s,double velocity){
    double iterations;
    CollisionType x;
    if(!ActiveRover)
       throw std::runtime_error("Error: MoveRover() - No active rover"); 
    if(velocity == 0)
        return;
    if(abs(velocity)>ActiveRover->returnVelocity()){    // sprawdzanie czy przekroczono max predkosc
        if(velocity<0)                                  //jesli tak to ustawiamy max predkosc
            velocity = -ActiveRover->returnVelocity();
        else
            velocity = ActiveRover->returnVelocity();}
    iterations = FPS*s/abs(velocity);                    //ilosc klatek
    while(iterations>1){
        ActiveRover->MoveRover(velocity/FPS);
        Lacze.Rysuj();
        usleep(1000000/FPS);
        --iterations;
        x = CheckCollisions();
        if(x == CT_Collision){                           // jesli kolizja
            for(int i=0;i<10;++i){
                ActiveRover->MoveRover(-velocity/FPS);
                ActiveRover->Count_and_save_tops();
                Lacze.Rysuj();
                usleep(1000000/FPS);}
            return;}
        else if(x == CT_CanCollect){                     //jesli kolizja probki z lazikiem sfr
            return;
            }
        }
    if(iterations>0){ // sytuacja gdy zostala 1 klatka lub mniej
        ActiveRover->MoveRover(iterations*velocity/FPS);
        ActiveRover->Count_and_save_tops();
        Lacze.Rysuj();
    }
}

void Scene::RotateRover(double angle){
    double velocity = ActiveRover->returnVelocity();
    double iterations;
    CollisionType x;
    if(!ActiveRover)
       throw std::runtime_error("Error: RotateRover() - No active rover"); 
    if (angle<0)
        velocity = -velocity;
    iterations = FPS*angle/velocity;
    while(iterations>1){
        ActiveRover->RotateRover(velocity/FPS);
        ActiveRover->Count_and_save_tops();
        Lacze.Rysuj();
        usleep(1000000/FPS);
        --iterations;
        x = CheckCollisions();
        if(x == CT_Collision){
            for(int i=0;i<10;++i){
                ActiveRover->RotateRover(-velocity/FPS);
                ActiveRover->Count_and_save_tops();
                Lacze.Rysuj();
                usleep(1000000/FPS);}
            return;}
        else if(x == CT_CanCollect){                     //jesli kolizja probki z lazikiem sfr
            return;
            }
        }
    if(iterations>0){   // sytuacja gdy zostala 1 klatka lub mniej
        ActiveRover->RotateRover(iterations*velocity/FPS);
        ActiveRover->Count_and_save_tops();
        Lacze.Rysuj();
    }

}

void Scene::Drive_test(){
    for(int i=0;i<=360;++i){
        MoveRover(0.5,20);
        RotateRover(1);
    }
    for(int i=0;i<=360;++i){
        MoveRover(0.5,20);
        RotateRover(-1);
    }

}

CollisionType Scene::CheckCollisions() const{
    for(std::shared_ptr<Object> x:Objects){
        switch (x->IsCollision(ActiveRover)){
            case CT_NoCollision:
                break;
            case CT_Collision:
                if(x->ReturnType()==Sample){
                    std::cout<<x->ReturnObjectName()<<" pod kolami lazika"<<std::endl;
                    return CT_Collision;
                }
                if(ActiveRover->ReturnObjectName()!=x->ReturnObjectName()){
                    std::cout<<"Zatrzymano ruch"<<std::endl<<"Kolizja z Lazikiem "<<x->ReturnObjectName()<<std::endl;
                    return CT_Collision;
                }
                break;
            case CT_CanCollect:
                std::cout<<"Zatrzymano ruch"<<std::endl<<"Wykryto probke "<<x->ReturnObjectName()<<". Mozna ja podjac"<<std::endl;
                return CT_CanCollect;
                break;
            case CT_RunOverSample:
                system("clear");
                std::cout<<"Przejazd nad "<<x->ReturnObjectName()<<std::endl;
                break;
            }
        }
    return CT_NoCollision;
}

void Scene::CollectSample(){
    int size = Objects.size();
    std::list<std::shared_ptr<Object>>::const_iterator Itr = Objects.begin();
    if (!(ActiveRover->ReturnType()==RoverSFRT)){
        std::cout<<"Lazik nie jest SFR"<<std::endl;
        return;}
    for(int i = 0;i<size;++i){
        if((*Itr)->IsCollision(ActiveRover)==CT_CanCollect){
            std::static_pointer_cast<RoverSFR>(ActiveRover)->AddSampleToList(Objects,Itr);
            Draw();
            return;}
        ++Itr;
    }
    std::cout<<"Nie ma probki w poblizu";
}
