# Get Next Line
The aim of this project was to create a function that, when given a file descriptor or the standard input, would return the first line contained in the file. 
A second call of the function would return the second line of the file and so on. The key takeaways from this project were the use of static variables and how the ``read`` function works.

The ideia of the bonus was to modify the function so that it could handle more file descriptors at a time. This was implimented by storing the file descriptors on an int array. This array was initialized with 
the ``FOPEN_MAX`` which is the maximum number of files descriptors that may be open at a time.
