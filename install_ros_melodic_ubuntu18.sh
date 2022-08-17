#!/bin/bash

#Adiciona o repositório padrão do ros no /apt/sources.list.d
sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
#Instala o curl, caso ainda não tenha sido e o atualiza caso já esteja presente
sudo apt -Vy install curl
#Utiliza o curl para baixar a chave de verificação do ros e a adiciona ao apt
curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
#Atualiza os repositórios de pacotes do apt
sudo apt update
#
sudo apt install -Vy ros-melodic-desktop-full ros-melodic-ar-track-alvar ros-melodic-usb-cam 
echo "source /opt/ros/melodic/setup.bash" >> ~/.bashrc
source ~/.bashrc

sudo apt install -Vy python-rosdep python-rosinstall python-rosinstall-generator python-wstool build-essential
sudo rosdep init
rosdep update
