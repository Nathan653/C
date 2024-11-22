Iterative : Uses a single stack frame, regardless of n.
            It is memory efficient and avoids stack overflow, as the stack depth remains constant.

Recursive : Creates a new stack frame for each call, 
            with stack depth growing linearly with n. 
            This can lead to high memory usage and risk of stack overflow for large n.