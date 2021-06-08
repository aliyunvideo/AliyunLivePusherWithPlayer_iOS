Pod::Spec.new do |s|

  s.name         = "AlivcLivePusherWithPlayer"
  s.version      = "4.1.0"
  s.summary      = "AlivcLivePusherWithPlayer_iOS"
  s.description  = <<-DESC
                   It's an SDK for aliyun video vodplay, which implement by Objective-C.
                   DESC
  s.homepage     = "https://github.com/aliyunvideo/AliyunLivePusherWithPlayer_iOS.git"
  s.license      = { :type => "MIT", :file => "LICENSE" }
  s.author       = { "aliyunvideo" => "videosdk@service.aliyun.com"}
  s.platform     = :ios, "8.0"
  s.source       = { :git => "https://github.com/aliyunvideo/AliyunLivePusherWithPlayer_iOS.git", :tag => "#{s.version}" }

  s.subspec 'AlivcLivePusherWithPlayer' do |pusher_playersdk|
  pusher_playersdk.vendored_frameworks = 'RtsSDK.framework','queen.framework','pixelai.framework','opencv2.framework','MNN.framework','FaceDetection.framework','Face3D.framework','AlivcLibArtp.framework','AlivcLivePusher.framework','AlivcLibRtmp.framework','AliyunPlayerSDK.framework','AlivcLibBeauty.framework','AlivcLibFace.framework','AliThirdparty.framework'

  pusher_playersdk.resource = 'AlivcLibFaceResource.bundle','AliyunLanguageSource.bundle'
# pusher_playersdk.frameworks = 'MediaPlayer','CoreGraphics'
  end

end
