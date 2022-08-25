with import <nixpkgs> {};
mkShell rec {
  name = "master-programming-task";
  buildInputs = [ boost catch2_3 ];
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
  CMAKE_GENERATOR = "Ninja";
  shellHook = ''
    echo Welcome to ${name} environment!
  '';
}
