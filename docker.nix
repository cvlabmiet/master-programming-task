# nix-build docker.nix
# docker load -i ./result

{ pkgs ? import <nixpkgs> {} }:

let
  shell = import ./shell.nix;
  dateFile = pkgs.runCommand "createdAt.txt" { envVariable = true; } ''date -Iseconds > $out'';
  createdAt = pkgs.lib.removeSuffix "\n" (builtins.readFile dateFile);

in pkgs.dockerTools.buildImage {
  name = "cxx-miet";
  tag = "0.2";
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
