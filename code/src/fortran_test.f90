program fortran_test
    implicit none
    real(kind=8),dimension(:),allocatable :: a,r
    integer :: status,i
    integer :: n = 120000000
    real :: start_time,stop_time

    ! allocate memory
    allocate(a(1:n),stat=status)
    allocate(r(1:n),stat=status)

    ! initialize function argument
    forall(i = 1:n) a(i) = i

    call cpu_time(start_time)
    r = sin(a) 
    call cpu_time(stop_time)
    write(*,*) r(1)
    write(*,*) r(60000000)
    write(*,*) r(120000000)
    write(*,*) "Elapsed time in seconds: ",stop_time-start_time

    deallocate(a,stat=status)
    deallocate(r,stat=status)
end program 
