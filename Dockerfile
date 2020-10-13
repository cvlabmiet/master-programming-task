FROM ubuntu:20.10
LABEL name="che-cxx-miet"
LABEL version="0.1"

RUN apt update
RUN apt install -y g++
RUN apt install -y cmake
RUN apt install -y catch2
RUN apt install -y valgrind
RUN apt install -y libboost-all-dev
RUN apt install -y ninja-build

VOLUME /projects
WORKDIR /projects

# avoid problem with GLIBCXX_3.4.26
ENV LDFLAGS="-static-libstdc++"

CMD ["tail", "-f", "/dev/null"]
