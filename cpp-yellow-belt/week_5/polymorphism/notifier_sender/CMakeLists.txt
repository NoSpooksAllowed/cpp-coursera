cmake_minimum_required(VERSION 3.5)

project(notifier_sender)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
        main.cpp
        senders.cpp
        sms_notifier.cpp
        email_notifier.cpp
)

set(HEADERS
        senders.h    
        i_notifier.h
        sms_notifier.h
        email_notifier.h
)

add_executable(notifier_sender ${SOURCES} ${HEADERS})
set_target_properties(
        notifier_sender PROPERTIES
        CXX_STANDART 17
        CXX_STANDART_REQUIRED ON
)

target_compile_features(notifier_sender PUBLIC cxx_std_17)
