//use python3 -m http.server to run
//type localhost:8000 to visualize in web browser

function main() 
{
    const width = window.innerWidth;
    const height = window.innerHeight;

    const svg = document.createElementNS('http://www.w3.org/2000/svg','svg');
    console.log(svg);
    svg.setAttribute("width", width);
    svg.setAttribute("height",height);
    document.body.appendChild(svg);

    const rectx = document.createElementNS('http://www.w3.org/2000/svg','rect');
    rectx.setAttribute('x', 20);
    rectx.setAttribute("width", 10);
    rectx.setAttribute("height", height);
    rectx.setAttribute('mask','url(#circle-mask)');
    svg.appendChild(rectx);

}