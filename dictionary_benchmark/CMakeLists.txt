if(UNIX)
	set(EXTRA_LIBS pthread)
else()
	set(EXTRA_LIBS shlwapi.lib)
endif()

add_executable(dictionary_benchmark
	benchmark.cc
	util.hh
	../spellchecker/tokenizer.hh
	../v0/dictionary.hh
	../string_view.hh
)

target_include_directories(dictionary_benchmark SYSTEM PRIVATE "ext")

target_link_libraries(dictionary_benchmark
	benchmark
	${EXTRA_LIBS}
)
