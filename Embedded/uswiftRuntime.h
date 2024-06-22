_Bool main_loop_running();

// noop by default, can be overridden
void _microswift_array_out_of_bounds(int* index, int lowerBound, int upperBound);
void _microswift_class_creation_attempt_oom(int size);
