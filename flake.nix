{
  description = "C/C++ GCC dev shell";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-26.05";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    self,
    nixpkgs,
    flake-utils,
  }:
    flake-utils.lib.eachDefaultSystem (
      system: let
        pkgs = import nixpkgs {inherit system;};
      in {
        devShells.default =
          pkgs.mkShell.override
          {
            stdenv = pkgs.gcc16Stdenv;
          }
          {
            nativeBuildInputs = with pkgs; [
              llvmPackages_latest.clang-tools

              doxygen
            ];
          };
      }
    );
}
