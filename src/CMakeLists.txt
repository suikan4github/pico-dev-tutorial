

add_executable("${PROJECT_NAME}" 
        main.cpp
        counter.cpp
        four2sevendecoder.cpp
        )

    # pull in common dependencies
    target_link_libraries("${PROJECT_NAME}" PUBLIC
                            pico_stdlib 
)


# create map/bin/hex file etc.
pico_add_extra_outputs("${PROJECT_NAME}")