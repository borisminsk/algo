std::vector<unsigned int> prime;

void eratosfen(unsigned int limit)
{
    unsigned int* bitmap = (unsigned int*) calloc(limit / 64 + ((limit & 63) ? 1 : 0), sizeof(unsigned int));
    //printf("2 3 ");
    prime.push_back(2);
    prime.push_back(3);
    unsigned int max_prime = 3;
    bool need_fill = true;
    while(need_fill) {
        unsigned int step = max_prime << 1;
        for(unsigned int i = max_prime * max_prime; i < limit; i += step) { // Вычеркиваем кратные max_pr
            bitmap[i >> 6] |= (1 << ((i >> 1) & 31));
        }
        if(max_prime * max_prime >= limit) need_fill = false; // дальше заполнять не надо
        // вычитываем следущую порцию
        for(unsigned int i = max_prime + 2; i < limit; i += 2) {
            if((bitmap[i >> 6] & (1 << ((i >> 1) & 31))) == 0) {
                prime.push_back(i);
                //printf("%u ", i);
                if(need_fill) {
                    max_prime = i;
                    break;
                }
            }
        }
    }
    free(bitmap);
}
