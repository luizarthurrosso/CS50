document.addEventListener('DOMContentLoaded', function(){

    // title blinking
    function title() {
        let bar = document.querySelector('.bar');
        if (bar.style.visibility == 'hidden')
            {
                bar.style.visibility = 'visible';
            }
            else
            {
                bar.style.visibility = 'hidden';
            }
    }
    window.setInterval(title, 500);

    // scroll homepage
    let content = document.querySelector('#homenav');
    let btn = document.querySelectorAll('.homebtn');
    let arrow = document.querySelector('#arrow');
    let hr = document.querySelector('hr');

    window.addEventListener('scroll', function()
    {
        //page current offset
        var offset = window.scrollY;

        //arrow;
        if (offset >= hr.offsetTop)
        {
            arrow.style.top = (offset * 1.1)+ 'px';
            arrow.style.opacity = 1 - offset/content.offsetTop;
        }

        //buttons
            if (content.style.opacity <= 0){
                content.style.visibility = 'hidden';
            } else {
                content.style.visibility = 'visible';
            }
            content.style.opacity = ((offset/content.offsetTop) - 0.7) * 3;
            if (offset == window.innerHeight){
                content.style.opacity = 1;
                for(let i = 0; i < btn.length; i++){
                btn[i].classList.add('ready');
                }
            } else{
                for(let i = 0; i < btn.length; i++){
                    btn[i].classList.remove('ready');
                }
            }
    })

});