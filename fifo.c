#include <stdio.h>

int main() {
    int frames, pages, i, j, k, flag, hits, faults = 0, index = 0;

    printf("Enter size of the frames: ");
    scanf("%d", &frames);

    printf("Enter number of pages in string: ");
    scanf("%d", &pages);

    int frame[frames], page[pages];

    printf("Enter page reference string:\n");
    for(i = 0; i < pages; i++)
        scanf("%d", &page[i]);

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    for(i = 0; i < pages; i++) {
    //default zero
        flag = 0;

        for(j = 0; j < frames; j++) {
            if(frame[j] == page[i]) {
            hits++;
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            frame[index] = page[i];
            index = (index + 1) % frames;
            faults++;
        }

        for(k = 0; k < frames; k++)
            printf("\t%d ", frame[k]);
        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);
    printf("Total page Hits = %d\n", hits);

    return 0;
}
