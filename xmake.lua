-- define target

target("gogogo")
    -- set kind
    set_kind("binary")
    set_warnings("all")
    set_languages("cxx11")
    -- add filesaaa..
    
    add_files("chapter9/t9.34.cpp")
    --add_files("test.cpp")

    -- add_includedirs("./include")

    -- add_syslinks("pthread")

    -- add_links("gtest_main")
    -- add_links("gtest")
    -- add_linkdirs("./lib")

    set_symbols("debug")
    -- add_cxflags("-g", "-O2", "-DDEBUG")
