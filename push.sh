ssh firefly "rm -rf /home/firefly/freddy/model_svc/src_bk ;mv /home/firefly/freddy/model_svc/src /home/firefly/freddy/model_svc/src_bk"
scp -r src firefly:/home/firefly/freddy/model_svc/
#ssh firefly "pushd /home/firefly/freddy/benchmark; /home/firefly/freddy/benchmark/cmake.sh; popd"