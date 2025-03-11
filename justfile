set dotenv-load

curr_dir := invocation_dir_native()
run_leetcode := "scripts/run_leetcode_cli.sh"
gen_readme := "scripts/gen_readme.sh"

test path="": (_run "test" path)

submit path="": (_run "submit" path)

testx pattern : (_find_and_run "test" pattern)

submitx pattern : (_find_and_run "submit" pattern)

update_readme:
	{{gen_readme}} README.md

_run mode path: && (_run_with_abspath mode join(curr_dir, path))
	@if [ -z "{{path}}" ]; then echo "note: using the current directory as the target"; fi;

_run_with_abspath mode abspath:
	{{run_leetcode}} {{mode}} "{{abspath}}"

_find_and_run mode pattern :
	{{run_leetcode}} {{mode}} $( fzf -q "/{{pattern}}/.cpp" )