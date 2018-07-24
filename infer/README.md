# Facebook Infer

> Infer checks for null pointer dereferences, memory leaks, coding conventions and unavailable API’s.

## Facts
- Static analyzer
- Open Sourced in 2015
- Mobile first
- Supports Java, C++, ObjC and C (First-gen Smartphone languages)
- Written in OCaml
- MIT licensed
- Has scripting language (AL) [AL]

## Claims
- Catches some errors other tools miss
- Scales

## Usage
- Two step process
- Needs compile commands
  
  As input:
  - Uses LLVM format
  - Wraps your buildtool

### Prepare
```bash
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=TRUE
```

```bash
# Using your favorite build system
infer capture make all

# Or using compile_commands.json
infer capture --compilation-database compile_commands.json
```

## Examples
- AL [ALE]
- Hello.m
- Etc2Comp

## Personal conclusion
- Mature tool
- Lots of integration
- Not easy to extend
- Use if you already have full sanitizers workflow working

[AL] https://code.fb.com/developer-tools/al-a-new-declarative-language-for-detecting-bugs-with-infer/
[ALE] https://github.com/facebook/infer/blob/master/infer/tests/codetoanalyze/cpp/linters-for-test-only/linters_example.al
