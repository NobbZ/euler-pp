{
  inputs.nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";

  outputs = { self, nixpkgs }:
    let pkgs = import nixpkgs { system = "x86_64-linux"; };
    in
    {
      devShell.x86_64-linux = pkgs.mkShell {
        pname = "aoc-c-shell";

        packages = [ pkgs.gnumake pkgs.cmake pkgs.bear pkgs.doxygen pkgs.graphviz pkgs.meson pkgs.mesonlsp pkgs.ninja pkgs.clang-tools pkgs.catch2_3 pkgs.pkg-config ];
      };
    };
}
