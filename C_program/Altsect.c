replacementSelction() {
    for (int i = 0 ; i < m ; i++) {
        written[i] = true;
        i = 0;
    }
    do
    {
        readFrom(Buffer[i], input);
        written[i] = false;
        i += 1;
    } while (!eof(input) && i != m);
    
    while (eof(input))
    {
        for (int i = 0; i < m; i++)
        {
            if (!written[i])
            {
                frozen[i] = false;
            }
            while (any unfrozen records remain)
            {
                Buffer[s] = smallest unforzen record;
                appendToRun(Buffers[s]);
                lastKey = Buffer[s].key;
                written[s] = true;
                frozen[s] = true;
                if (!eof(input)) {
                    readFrom(new Buffer[s], input);
                    written[s] = false;
                    if (Buffer[s].key > lastKey)
                            frozen[s] = false;
                }
            }
            
        }
        
    }
    
}