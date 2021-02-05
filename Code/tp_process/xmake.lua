
target("tp_process")
    set_kind("binary")
    set_group("Client")
    add_includedirs(
        ".",
        "../../Libraries/TiltedUI/Code/ui_process/include/",
        "../../Libraries/TiltedUI/ThirdParty/CEF/")
    add_headerfiles("*.h")
    add_files("*.cpp")
    add_deps("UiProcess")
    add_packages("tiltedcore", "hopscotch-map")