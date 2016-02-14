add_library(plugin_manager
	i_plugin.hh i_plugin.cc
	plugin_manager.hh plugin_manager.cc
)

target_include_directories(plugin_manager INTERFACE ..)

target_link_libraries(plugin_manager Qt5::Core)
