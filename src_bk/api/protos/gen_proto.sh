rm -f model.grpc.pb.cc  model.grpc.pb.h  model.pb.cc  model.pb.h
protoc -I . --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` ./model.proto
protoc -I . --cpp_out=. ./model.proto
