require('dotenv').config()
const express = require('express')
var app = express();

app.use(express.urlencoded( {extended : false } )); 
app.use(express.json()); //json 형태로 parsing




const jwt = require('jsonwebtoken')
app.post('/login',(req,res)=>{
    console.log(req.body)
    const username = req.body.username
    const user = {name: username}

    const accessToken = jwt.sign(user,process.env.ACCESS_TOKEN_SECRET)

    res.json({"accessToken" : accessToken})
})

function authenticateToken(req,res,next){
    const authHeader = req.headers['authorization']
    const token = authHeader && authHeader.split(' ')[1]

    if(token == null) return res.sendStatus(401)

    console.log(token===process.env.ACCESS_TOKEN_SECRET)
    jwt.verify(token,process.env.ACCESS_TOKEN_SECRET,(err,user)=>{
        if(err) {
            console.log(err)
            return res.sendStatus(403)
        }
        req.user = user
        next()
    })
}
app.listen(4000)