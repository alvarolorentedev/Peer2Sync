# Peer2Sync

Peer to server syncronization using c++ high performance web server with a redis backend through JSON-RPC 2.0 requests. The code is contained in a docker container to simplify the deployment.

## Deployment

Download the container from the docker-hub
```
docker pull kanekotic/p2s
```

And execute with the next command
```
docker run -p <service port> -e PORT=<service port> -e REDIS_IP=<redis ip> -e REDIS_PORT=<redis port> --net=host kanekotic/p2s
```

## Development

Current development enviroment is based on un an Ubuntu machine. Please follow the next steps to setup the enviroment: 

- Basic building will require the next packages
```
sudo apt-get install redis-server libboost-all-dev gcc-5 g++-5 libgtest-dev cmake qt5-qmake qt5-default qtbase5-dev qttools5-dev-tools
```
- To build gtest run 
```
cd /usr/src/gtest
sudo cmake .
sudo cmake --build . 
sudo mv libg* /usr/local/lib/
```
- you will also need to pull the dependency for the redis client trought
```
git clone https://github.com/Cylix/cpp_redis.git 
cd cpp_redis 
mkdir build 
cd build 
cmake .. 
make -j 
sudo make install -j 
sudo cp /usr/local/lib/libcpp_redis.so /usr/lib/libcpp_redis.so
```
- the code can be build using the next command line on the directory
```
qmake 
make
```
**optional**

- Use ```Qt Creator``` as development enviroment, it can be installed by:
```
sudo apt-get install qtcreator
```
- Install and use Postman for integration testing (```./test/Test_P2S_Postman.json```).
