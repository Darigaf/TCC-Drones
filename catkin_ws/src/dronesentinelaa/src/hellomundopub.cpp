#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "mensagemPub"); /*argc e argv precisa pra iniciar o ros, o terceiro é o nome do node*/
    ros::NodeHandle n; //Cria uma node que lida com a inicialização da node, bem só precisa disso pra iniciar o node/codigo
    // e é uma variavel o n

    ros::Publisher testemensagem_pub = n.advertise<std_msgs::String>("testemensagem", 1000);
    //cria um ros::Publisher chamado testemensagem_pub, que vai receber uma mensagem do tipo std_msgs::String, a segunda parte é o limite da msg
    //NodeHandle::advertise/ n.advertise retorna um objeto ros::Publisher, isso serve pra usar um dos tópicos q tem para mandar
    //a mensagem, e também pra acabar o escorpo do código sem dar bug e essas coisas q n entendi
    ros::Rate loop_rate(10);
    //define a frequencia de loop, a frequencia ocorre quando bota o loop;sleep, definindo nesse exemplo em 10Hz
    int qtd = 0;
    while (ros::ok()) //add a opção de ctrc_c para finalizar a ação caso queira, ou de outro problema, catch and try só que melhor
    {
        std_msgs::String mensagem;
        std::stringstream sstrea;
        sstrea << "hellow lmao mundo" << qtd; // converte ae a msg "hellow..." e junta com o qtd
        mensagem.data = sstrea.str(); // passa para ser printado em String n sei pq o data ainda

        ROS_INFO("%s", mensagem.data.c_str());// ROS_INFO é o printf do ros
        testemensagem_pub.publish(mensagem);// agora a mensagem esta realmente pronta para ser printada e é publicada
        ros::spinOnce();// confere se tem callbakcs, que seria funções que você em si n ativa, e sim define quando ela vai ser chamada
        // e funciona de maneira meio que automática/passiva
        // caso n pode o spinOnce, os callbacks(subscribers) nunca seriam chamados

        loop_rate.sleep();//faz a gente ter o tempo para dar os 10hz q definimos antessss, 
        ++qtd;
    }
    return 0;
}
