import express, { Request, Response } from 'express'
import path from 'path'
import socketio from 'socket.io'
import http from 'http'
import serialport from 'serialport'

const app = express()
const server = http.createServer(app)
const io = socketio.listen(server)

const Readline = serialport.parsers.Readline
const port = new serialport("COM5", {
    baudRate: 9600
})
port.on('open', () => {
    console.log('Conexão com a porta efetuada')
})




app.use(express.static(path.join(__dirname, 'public')));
app.set('view engine', 'ejs')
app.set('views', path.join(__dirname, './views'))

app.use("/", (req: Request, res: Response) => {
    res.render("game")
})

io.on('connect', socket => {
    port.on('data', (data) => {
        const object = JSON.parse(data.toString());
        socket.emit('move',object)
    })
})

server.listen(3000 || process.env.PORT)