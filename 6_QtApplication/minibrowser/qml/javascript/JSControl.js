function call_window(window) {

    webPage.visible = false
    trekPage.visible = false
    currentTrekPage.visible = false
    photoPage.visible = false
    uploadPage.visible = false
    window.visible = true

}

function lastLat(){
    var temp = MyContext.myTrek.path[MyContext.myTrek.path.length-1]
    return temp ? temp.latitude : undefined
}

function lastLng(){
    var temp = MyContext.myTrek.path[MyContext.myTrek.path.length-1]
    return temp ? temp.longitude : undefined
}

function pathwayToJSon(){
    var pathway = [];
    var index = 0;

    while(index < MyContext.myTrek.path.length)
    {
        pathway.push( {  latitude : MyContext.myTrek.path[index].latitude ,
                         longitude :MyContext.myTrek.path[index].longitude } );
        index++
    }

    return pathway
}

function traceToJSon(){
    var trace = [];
    var index = 0;

    while(index < MyContext.myTrek.trace.length)
    {
        trace.push( {   latitude : MyContext.myTrek.trace[index].latitude ,
                        longitude :MyContext.myTrek.trace[index].longitude } );
        index++
    }

    return trace
}


function timeToString(timeInMs){

    var cents = parseInt( timeInMs/10, 10 ) ;

    var seconds = parseInt( cents/100, 10 ) ;
    cents %= 100 ;

    var minutes = parseInt( seconds/60, 10 ) ;
    seconds %= 60 ;

    var hours = parseInt( minutes/60, 10 ) ;
    minutes %= 60 ;

    var numToString = function( number ){
        var numString = number.toString();
        if(number < 10)
        {
            numString = "0" + number.toString();
        }
        return numString;
    };

    var timeInString =  numToString(hours) + ":" +
                        numToString(minutes) + ":" +
                        numToString(seconds);
                        // + ":" + numToString(cents)

    return timeInString;
}

function getTreksJSON(idModel) {
    var uri = "http://localhost:3000/api-rest/users/3" //+ MyContext.getIdUser();

    var request = new XMLHttpRequest()
    request.open('GET', uri, true);

    request.onreadystatechange = function() {
        if (request.readyState === XMLHttpRequest.DONE && request.status == 200) {

            //console.log("response", request.responseText)
            var result = JSON.parse(request.responseText)

            for (var ligne in result.treks) {

                idModel.append({
                                      "label": result.treks[ligne].label,
                                      "length": result.treks[ligne].length,
                                      "time": result.treks[ligne].time
                                  })
            }

        } else {
            console.log("HTTP:", request.status, request.statusText)
        }
    }

    request.send()
}
