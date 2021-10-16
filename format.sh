find docs/*/code/*.cpp | xargs clang-format -i
remark ./docs -o -r .remarkrc
