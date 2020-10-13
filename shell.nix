with import <nixpkgs> {};
mkShell rec {
  name = "cxx-tasks";
  buildInputs = [ boost168 catch2 ];
  nativeBuildInputs = [
    cmake
    gnumake
    ninja
    gcc9
    binutils-unwrapped
    gdb
    valgrind
    strace
    openssl
    gawk
  ];
  hardeningDisable = [ "all" ];
}
