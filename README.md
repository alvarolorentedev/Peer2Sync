# ![logomakr_0ewpnu](https://cloud.githubusercontent.com/assets/3071208/17784932/e2b96a14-657e-11e6-9cf9-ad0000e3e18c.png)

##Intro

Protocol capable of P2P (master to master) syncing key-value datastores. using ```c++``` high performance web server with a redis backend. The path to requests is ```/rpc``` and takes only ```POST``` requests in ```JSON-RPC 2.0```. The  methods that have been implemented are:
- ```datastorePut({ collection: String, changes: [Object]  }) -> ```: sync objects to the server.
- ```datastoreGet({ collection: String, all: Boolean, ids: [String] }) -> [Object]```: retrieve all of the objects which are newer on the server.
- ```datastoreMeta({ collection: String }) -> [id,mtime]```: get last modification times of all objects upstream.

Arguments explanation:
- ```collection```: this is a string identifier of the collection we want to sync.
- ```changes```: this is an array of objects to save in the collection; every object can be anything (JSON object). Has three special properties:
  - ```_id```: (always required) is the object key/id. 
  - ```_mtime```: is the last time the object was modified. This is a [POSIX time](https://en.wikipedia.org/wiki/Unix_time) in millisecons.
  - ```_delete```: is set to true if we want to remove this object from the collection. If not it can be either false or not included.
- ```all```: this is a boolean which, when set to true, makes datastoreGet return all objects in the collection
- ```ids```: array of strings, specifies which objects to fetch from the database.

The implementation is integrated in Travis-CI, that will generate and publish automatically containers to easy deploy the application.


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
