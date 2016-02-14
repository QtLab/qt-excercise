add_library(plugin_interfaces
	i_city_provider.cc i_city_provider.hh
	i_plugin.hh i_plugin.cc
)

target_include_directories(plugin_interfaces INTERFACE ..)

target_link_libraries(plugin_interfaces Qt5::Core)
