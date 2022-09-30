# Learn SLAM Note

## Introduction

## libraries

### How to use Eigen
- install
```shell
sudo apt-get install libeigen3-dev
```

- search location
```shell
sudo apt install plocate
sudo updatedb
locate eigen3
```

### How to use pangolin
- clone
```shell
git clone https://github.com/stevenlovegrove/Pangolin.git
```
- dependencies
```shell
sudo apt-get install libglew-dev
sudo apt-get install cmake
sudo apt-get install libpython2.7-dev
sudo apt-get install ffmpeg libavcodec-dev libavutil-dev libavformat-dev libswscale-dev libavdevice-dev
sudo apt-get install libdc1394-22-dev libraw1394-dev
sudo apt-get install libjpeg-dev libpng-dev libtiff5-dev libopenexr-dev
```

- build
```shell
cd Pangolin
mkdir build
cd build
cmake ..
cmake --build .
```

- install
```shell
sudo make install
```

### How to use Sophus
- clone
```shell
git clone git@github.com:strasdat/Sophus.git
```
- build
```shell
cd ./Sophus/

mkdir build

cd ./build

cmake ../ -DUSE_BASIC_LOGGING=ON

make

sudo make install
```

- install fmt
```shell
git clone git@github.com:fmtlib/fmt.git
mkdir build 
cd build
cmake ..
make
sudo make install
```
