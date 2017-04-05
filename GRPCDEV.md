# GRPC Development setup

Install curl ```sudo apt-get install curl -y```

Follow [C++ GRPC isntructions](https://github.com/grpc/grpc/blob/master/INSTALL.md) to build from source


# Building protos for C++

```
cd marketplace
make
```

# Add a remote for Server code (needed for proto files)

```
git remote add EmulationServer https://github.com/tbhova/Emulation_ROM_Market_Server.git
git checkout -b serverBranch EmulationServer/master
```

# Updating the Server code proto files

See [git book](https://git-scm.com/book/en/v1/Git-Tools-Subtree-Merging)

```
git checkout serverBranch
git pull
git checkout master (or other branch)
git merge --squash -s subtree --no-commit serverBranch
```
