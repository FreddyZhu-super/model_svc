protoc -I . --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` ./algorithm.proto
protoc -I . --cpp_out=. ./algorithm.proto
