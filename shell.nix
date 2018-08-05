with import <nixpkgs> {};
mkShell rec {
  name = "cxx-tasks";
  buildInputs = [ boost catch ];
  nativeBuildInputs = [ cmake gnumake gcc8 gdb valgrind strace ];
  hardeningDisable = [ "all" ];

  env = pkgs.buildEnv {
    name = "gccenv";
    paths = buildInputs ++ nativeBuildInputs;
    extraOutputsToInstall = [ "dev" "include" "lib" ];
  };
}
