#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Simulated DMA Controller Registers (memory-mapped I/O)
volatile uint32_t* DMA_SRC_ADDR  = (uint32_t*)0x10000000; // Source address register
volatile uint32_t* DMA_DEST_ADDR = (uint32_t*)0x10000004; // Destination address register
volatile uint32_t* DMA_COUNT     = (uint32_t*)0x10000008; // Transfer count register
volatile uint32_t* DMA_CONTROL   = (uint32_t*)0x1000000C; // Control register

// DMA Control Register Bits
#define DMA_CONTROL_ENABLE    (1 << 0) // Enable DMA
#define DMA_CONTROL_START     (1 << 1) // Start transfer
#define DMA_CONTROL_IRQ_EN    (1 << 2) // Enable interrupt on completion
#define DMA_CONTROL_IRQ_FLAG  (1 << 3) // Interrupt flag (set when transfer completes)

// Function to initialize and start a DMA transfer
void dma_transfer(uint32_t src, uint32_t dest, uint32_t count) {
    // Set source address
    *DMA_SRC_ADDR = src;

    // Set destination address
    *DMA_DEST_ADDR = dest;

    // Set transfer count (number of words to transfer)
    *DMA_COUNT = count;

    // Configure control register:
    // - Enable DMA
    // - Enable interrupt on completion
    *DMA_CONTROL = DMA_CONTROL_ENABLE | DMA_CONTROL_IRQ_EN;

    // Start the DMA transfer
    *DMA_CONTROL |= DMA_CONTROL_START;
}

// Simulated Interrupt Service Routine (ISR) for DMA completion
void dma_isr() {
    printf("DMA Transfer Complete!\n");

    // Clear the interrupt flag
    *DMA_CONTROL &= ~DMA_CONTROL_IRQ_FLAG;
}

// Function to simulate waiting for DMA completion
bool is_dma_transfer_complete() {
    return (*DMA_CONTROL & DMA_CONTROL_IRQ_FLAG) != 0;
}

// Function to simulate the DMA transfer process
void simulate_dma_transfer() {
    // Simulate the DMA transfer by copying data from source to destination
    uint32_t src = *DMA_SRC_ADDR;
    uint32_t dest = *DMA_DEST_ADDR;
    uint32_t count = *DMA_COUNT;

    uint32_t* src_ptr = (uint32_t*)src;
    uint32_t* dest_ptr = (uint32_t*)dest;

    for (uint32_t i = 0; i < count; i++) {
        dest_ptr[i] = src_ptr[i]; // Copy data
    }

    // Simulate setting the interrupt flag to indicate completion
    *DMA_CONTROL |= DMA_CONTROL_IRQ_FLAG;
}

int main() {
    // Example data buffers
    uint32_t src_buffer[256];
    uint32_t dest_buffer[256];

    // Initialize source buffer with some data
    for (int i = 0; i < 256; i++) {
        src_buffer[i] = i + 1; // Fill with values 1, 2, 3, ..., 256
    }

    // Perform DMA transfer
    printf("Starting DMA Transfer...\n");
    dma_transfer((uint32_t)src_buffer, (uint32_t)dest_buffer, 256);

    // Simulate the DMA transfer process
    simulate_dma_transfer();

    // Wait for DMA transfer to complete
    while (!is_dma_transfer_complete()) {
        // Busy-wait (in a real system, you might sleep or yield here)
    }

    // Simulate ISR call
    dma_isr();

    // Verify data
    bool transfer_successful = true;
    for (int i = 0; i < 256; i++) {
        if (dest_buffer[i] != src_buffer[i]) {
            printf("Data mismatch at index %d: expected %d, got %d\n", i, src_buffer[i], dest_buffer[i]);
            transfer_successful = false;
            break;
        }
    }

    if (transfer_successful) {
        printf("DMA Transfer Verified Successfully!\n");
    }

    return 0;
}