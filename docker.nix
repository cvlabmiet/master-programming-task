# nix-build docker.nix --argstr createdAt $(date -Iseconds)
# docker load -i ./result

{ pkgs ? import <nixpkgs> {}, createdAt }:

let
  shell = import ./shell.nix;

in pkgs.dockerTools.buildImage {
  name = "cxx-miet";
  tag = "0.1";
  created = createdAt;
  contents = with pkgs; [ coreutils bashInteractive shell.env ];
  runAsRoot = ''
    mkdir /tmp
    chmod a+rw /tmp
  '';
  config = {
    Cmd = [ "bash" ];
    WorkingDir = "/data";
    Volumes = {
      "/data" = {};
    };
    Env = [
      "CMAKE_PREFIX_PATH=${shell.env.outPath}"
    ];
  };
}
