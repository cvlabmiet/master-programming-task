FROM ubuntu:20.10
LABEL name="che-cxx-miet"
LABEL version="0.1"

RUN apt update
RUN apt install -y g++ cmake catch2 valgrind libboost-all-dev ninja-build bash

VOLUME /projects
WORKDIR /projects

# avoid problem with GLIBCXX_3.4.26
ENV LDFLAGS="-static-libstdc++"

CMD ["tail", "-f", "/dev/null"]
