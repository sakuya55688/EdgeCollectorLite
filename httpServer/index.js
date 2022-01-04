const express = require("express");
const app = express();

app.get("/", (req, res) => {
    res.send("data website");
});

app.get('/data', (req,res) => {
    let data = JSON.parse(req.query.data);
    
    let temp = data.temp;
    let moist = data.moist;
    let sensor = data.sensorData;

    if(temp != undefined && moist != undefined){
        console.log("Tempereture " + temp);
        console.log("Moisture " + moist);
        console.log("Sensor " + sensor);
    }
    
    //console.log(json);
});

app.post('/sample', (req,res) => {
    let temp = req.query.t;
    let moist = req.query.m;

    if(temp != undefined && moist != undefined){
        console.log("Tempereture " + temp);
        console.log("Moisture " + moist);
    }

});

app.listen(8080, () => console.log("Server Running!!!"));