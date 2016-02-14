add_library(plugin_interfaces
	i_city_provider.cc i_city_provider.hh
)

target_link_libraries(plugin_interfaces Qt5::Core)
