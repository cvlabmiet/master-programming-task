with import <nixpkgs> {};
mkShell rec {
  name = "cxx-tasks";
  buildInputs = [ boost catch2 ];
  nativeBuildInputs = [
    cmake
    gnumake
    ninja
    gcc
    binutils-unwrapped
    gdb
    valgrind
    strace
    openssl
    gawk
  ];
  hardeningDisable = [ "all" ];
  CTEST_OUTPUT_ON_FAILURE = "ON";
  shellHook = ''
    tcmake() { cmake -GNinja $cmakeFlags "$@"; }
    export -f tcmake
    echo Welcome to ${name} environment!
  '';
}
