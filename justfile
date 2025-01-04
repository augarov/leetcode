curr_dir := invocation_dir_native()
run_leetcode := "scripts/run_leetcode_cli.sh"

test target="": (_run "test" target)

_run mode target:
	@if [ -z "{{target}}" ]; then echo "note: setting target directory as current"; fi
	{{run_leetcode}} {{mode}} "{{curr_dir}}/{{target}}"