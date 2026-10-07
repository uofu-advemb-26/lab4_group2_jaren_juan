add_executable(lab4_test_fifo ../test/test_fifo.c ../src/fifo.c ../src/signal.c ../test/unity_config.c)
target_link_libraries(lab4_test_fifo PRIVATE
  pico_stdlib
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
  pico_cyw43_arch_none
  unity
)
pico_enable_stdio_uart(lab4_test_fifo 0)
pico_enable_stdio_usb(lab4_test_fifo 1)
add_custom_target(flash_test_
    picotool load -f $<TARGET_FILE:lab4_test_fifo> DEPENDS lab4_test_fifo)


add_executable(lab4_test_signal ../test/test_signal.c ../src/signal.c ../test/unity_config.c)
target_link_libraries(lab4_test_signal PRIVATE
  pico_stdlib
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
  pico_cyw43_arch_none
  unity
)
pico_enable_stdio_uart(lab4_test_signal 0)
pico_enable_stdio_usb(lab4_test_signal 1)
add_custom_target(flash_test_signal
    picotool load -f $<TARGET_FILE:lab4_test_signal> DEPENDS lab4_test_signal)