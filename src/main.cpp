#include <program.h>

#include <CL/sycl.hpp>

int main(int argc, char** argv) {

    cl::sycl::queue queue;

    queue.submit([&](cl::sycl::handler& cgh) {
        sycl::stream os(2048, 2048, cgh);
        cgh.single_task<class hello_world>([=]() {
            os << "Hello SYCL world!" << "\n";
        });
    });

    queue.wait();

    DoStuff();
}
