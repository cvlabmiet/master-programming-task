with import <nixpkgs> {};
mkShell rec {
  name = "cxx-tasks";
  buildInputs = [ boost168 catch2 ];
  nativeBuildInputs = [ cmake gnumake gcc9 gdb valgrind strace binutils openssl gawk ];
  hardeningDisable = [ "all" ];
}
