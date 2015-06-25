test: out.s testexec.c
	gcc -o $@ $^

out.s: out.bc
	llc $<

out.bc: out.ll
	llvm-as $<

.PHONY: out.ll
out.ll: test.ceylon
	ceylon run --compile=check org.americanteeth.ceylon_llvm test.ceylon
