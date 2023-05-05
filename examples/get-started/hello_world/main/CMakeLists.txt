set(PRIV_REQUIRES_LIST esp_matter)

idf_component_register(SRCS "hello_world_main.c" "matter_main.cpp"
                    PRIV_REQUIRES ${PRIV_REQUIRES_LIST}
                    INCLUDE_DIRS "")

set_property(TARGET ${COMPONENT_LIB} PROPERTY CXX_STANDARD 14)
target_compile_options(${COMPONENT_LIB} PRIVATE "-DCHIP_HAVE_CONFIG_H")
