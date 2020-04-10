import React from 'react';
//tudo isso elemento 
//exporta tudo para fora
export default function Header({children}){
    //retorna o html
    return (
        <header>
            <h1>{children}</h1>
        </header>

    );
}