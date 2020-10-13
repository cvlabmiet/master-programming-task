# nix-build docker.nix
# docker load -i ./result
# docker run -u `id -u`:`id -g` -v $PWD:/projects -it cxx-miet:latest

{ pkgs ? import <nixpkgs> {} }:

let
  shell = import ./shell.nix;
  # include dev and out
  out-paths = shell.buildInputs ++ map (x: x.out) (shell.buildInputs ++ shell.nativeBuildInputs);

in pkgs.dockerTools.buildLayeredImage rec {
  name = "cxx-miet";
  tag = "0.3";
  created = "now";
  contents = [ pkgs.busybox ] ++ out-paths;
  config = {
    Cmd = [ "sh" ];
    WorkingDir = "/projects";
    Volumes = {
      "/projects" = {};
    };
    Env = [
      "CMAKE_PREFIX_PATH=${pkgs.lib.makeSearchPath "" out-paths}"
    ];
  };
  extraCommands = ''
    # for valgrind
    mkdir -m 1777 ./tmp
  '';
}
