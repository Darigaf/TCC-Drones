#include <vector>
#include <math.h>
#include <string>
#include "ros/ros.h"
#include "dronesentinelaa/DestinoMarca.h" //chama a msgs que tem conteudo facil, para usar só utilizar using pacote::nomedomsgs

#include "nav_msgs/Odometry.h"


//inclui com o tipo da msg, e dai oq vc quer usar em especifico
//odom serve para saber onde ele esta em relação ao inicio
//aqui estamos fazendo um callback, e inicializando no odom, 
//const nav... é uma variavel para entrar nesse metodo, o nav é a data usada no odom, vista com o rostopic info

using dronesentinelaa::DestinoMarca;
using std::vector;
using std::string;

class Marca { //objeto marca, basicamente a estrutura para criar o objeto Marca, feito com nome e cordenadas
    public:
     Marca(string name, double x, double y)
        : name(name), x(x), y(y) {}
     string name;
     double x;
     double y;
};

class MarcaMonitor{
    public: MarcaMonitor(): marcas_() { //métodos para chamar
        InitMarcas();
    }


 void OdomCallback(const nav_msgs::Odometry::ConstPtr& msg) { 
    double x = msg->pose.pose.position.x;
    double y = msg->pose.pose.position.y;
    DestinoMarca dm = AchaPerto(x,y);
    ROS_INFO("name: %f, distancia: %f", dm.name.c_str(), dm.distancia);//print do ros
    }
 private: vector<Marca> marcas_;

 DestinoMarca AchaPerto(double x, double y){
    DestinoMarca resultado;
    resultado.distancia = -1;

    for (size_t i= 0; i< marcas_.size(); ++i){
      const Marca& marca = marcas_[i];
      double xd = marca.x - x;
      double yd = marca.y - y;
      double distancia = sqrt(xd*xd + yd*yd);

      if (resultado.distancia < 0 || distancia < resultado.distancia ){
         resultado.name = marca.name;
         resultado.distancia = distancia;
    }

    }
    return resultado;
 }
   
 void InitMarcas(){
    marcas_.push_back(Marca("Ponto 1", -1.390695, -0.514655)); 
    marcas_.push_back(Marca("Ponto 2", 0, 0));
    marcas_.push_back(Marca("Ponto 3", -2.000026, -0.499958));
    marcas_.push_back(Marca("Ponto 4", 60.00, -70.23));//as marcas
 }
};
int main(int argc, char** argv) {
    ros::init(argc, argv, "posicao_monitor");
    ros::NodeHandle nh; //padrão pra conectar/ iniciar node
    MarcaMonitor monitor;
    ros::Subscriber sub = nh.subscribe("odom", 100, &MarcaMonitor::OdomCallback, &monitor);//ler tutorial pub sub ros, coisa basica pra qualquer pub/sub
    // Ir no marcamonitor:: CHamar odomCallback, usando o monitor.
    ros::spin();
    return 0;
}