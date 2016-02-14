add_library(plugin_manager
	plugin_manager.hh plugin_manager.cc
	extension_manager.cc extension_manager.cc
)

target_include_directories(plugin_manager INTERFACE ..)

target_link_libraries(plugin_manager

	plugin_interfaces

	Qt5::Core
)
